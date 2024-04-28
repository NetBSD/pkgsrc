#!/bin/sh
#
# $NetBSD: check-hackage.sh,v 1.1 2024/04/28 10:58:06 pho Exp $
#
: ${CURL:=curl}
: ${JQ:=jq}
: ${HACKAGE_URL:=https://hackage.haskell.org}

# Abort if tools are missing.
if ! type "${CURL}" >/dev/null 2>&1; then
    echo >&2 "$0: ${CURL} is missing. Please install \`www/curl' first."
    exit 1
fi
if ! type "${JQ}" >/dev/null 2>&1; then
    echo >&2 "$0: ${JQ} is missing. Please install \`devel/jq' first."
    exit 1
fi

# Abort if arguments are missing.
if [ $# -lt 1 ]; then
    echo >&2 "Usage: $0 {DISTNAME}"
    exit 1
fi
readonly DISTNAME="$1"
readonly pkgname="${DISTNAME%%-[0-9]*}"
readonly pkgversion="${DISTNAME#${pkgname}-}"

#
# Example contents of ${pkgname}.json:
# {
#     "0.0.0.1": "normal",
#     "0.0.0.2": "deprecated",
#     "0.0.0.3": "normal",
#     "0.0.0.4": "normal"
# }
#
# So we drop deprecated versions and pick the greatest one.
#
pkg_info_json="$(${CURL} --silent --show-error --fail "${HACKAGE_URL}/package/${pkgname}.json")"
if [ $? -ne 0 ]; then
    echo >&2 "$0: Failed to retrieve package info for ${pkgname}."
    exit 1
fi

readonly latest=$(
    echo "$pkg_info_json" |
        ${JQ} --raw-output '
            def split_pvp:
                split(".") | map(tonumber);
            map_values(if . == "normal" then . else empty end) |
            keys |
            sort_by(split_pvp) |
            last
            ')

if [ "$latest" = "$pkgversion" ]; then
    echo "${DISTNAME} is up to date."
else
    echo "A new version ${pkgname}-${latest} is available."
    echo "Consider updating the package:"
    echo "    ${HACKAGE_URL}/package/${pkgname}-${latest}"
fi
