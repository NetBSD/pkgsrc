# $NetBSD: developer.mk,v 1.1 2024/04/28 10:58:06 pho Exp $
#
# Targets for pkgsrc developers for updating Haskell packages.
#
# check-hackage:
#	Check for the Hackage repository to see if there is an update to
#	the ${PKGPATH}.

.PHONY: check-hackage
check-hackage:
	${RUN} ${SH} ../../mk/haskell/check-hackage.sh "${DISTNAME}"
