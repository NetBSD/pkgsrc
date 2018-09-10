#!@SH@
#
# example usage from .qmail:
# | condtomaildir ./Maildir/.Spam qmail-isspam-rspamd

@PREFIX@/bin/rspamc --mime | @GREP@ -q '^X-Spam: yes$'
