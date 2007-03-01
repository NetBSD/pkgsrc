#!@SH@
#
# Wrapper for relay-ctrl-allow that sets TCPREMOTEIP.

TCPREMOTEIP="${IP}"; export TCPREMOTEIP
exec "$@"
