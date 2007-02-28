#!@SH@
#
# Wrapper for relay-ctrl-allow that sets TCPREMOTEIP by massaging
#   Dovecot login info.

TCPREMOTEIP=`@ECHO@ "$@" | @SED@ -e 's|.* ||' -e 's|]$||'`
export TCPREMOTEIP

exec "$@"
