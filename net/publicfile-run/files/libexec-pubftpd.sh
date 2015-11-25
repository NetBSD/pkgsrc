#!/bin/sh

#
# Executes tcpserver with "pubftpd" as the 0th argument and with a fixed banner
# appropriate for DJB's publicfile FTP server.
#
# The reason for this script, as opposed to invoking tcpserver directly, is
# that the banner (specified with the -B option) needs to include a trailing
# carriage-return and newline (\015\012) which is difficult, if not impossible,
# to specify in a NetBSD rc(8) script because rc(8) uses "eval" to evaluate the
# constructed command.
#

exec @PREFIX@/bin/argv0 @PREFIX@/bin/tcpserver pubftpd \
-B'220 Features: a p .
' "$@"
