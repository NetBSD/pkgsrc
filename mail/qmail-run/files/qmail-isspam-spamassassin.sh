#!@SH@
#
# example usage from .qmail:
# | condtomaildir ./Maildir/.Spam qmail-isspam-spamassassin

@PREFIX@/bin/except @PREFIX@/bin/spamc -c
