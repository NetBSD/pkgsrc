#!@SH@
#
# Wrapper for qmail-queue that filters messages before injecting
#   into the queue.
#
# Using this wrapper, executable filters:
# * Must be placed in @PKG_SYSCONFDIR@/filters
# * Must have filenames matching "qfilter-*"
# * Will be executed with no arguments
# * Will be executed in sort(1) order
#
# To use this script to filter messages arriving via SMTP, set the
# QMAILQUEUE environment variable in tcp.smtp like so:
#
# :allow,QMAILQUEUE="@PREFIX@/bin/qmail-qfilter-queue"
#
# Then rebuild the cdb.

possible_qfilters=`@ECHO@ @PKG_SYSCONFDIR@/filters/qfilter-* | @SORT@`
qfilters=""

if [ "${possible_qfilters}" = "@PKG_SYSCONFDIR@/filters/qfilter-*" ]; then
	qfilters="@CAT@"
else
	for qfilter in ${possible_qfilters}; do
		if [ -x "${qfilter}" ]; then
			qfilters="${qfilters} ${qfilter}"
		fi
	done
	[ -z "${qfilters}" ] && qfilters="@CAT@"
fi

qfilter_cmd="@LOCALBASE@/bin/qmail-qfilter `@ECHO@ ${qfilters} | @SED@ -e 's| | -- |g'`"

exec ${qfilter_cmd}
