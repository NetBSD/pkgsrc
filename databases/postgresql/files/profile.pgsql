# $NetBSD: profile.pgsql,v 1.1 2000/03/18 17:43:16 jlam Exp $
#
# profile - sets the enviroment for the postgresql superuser

PATH=@PATH@
MANPATH=@MANPATH@
#
# note: PGDATA overrides the -D startup option
#
PGDATA=${HOME}/data
PGLIB=@PREFIX@/share/postgresql
DISPLAY=:0

export PATH MANPATH PGDATA PGLIB DISPLAY

# if you want to make regression tests use this TZ
#TZ=PST8PDT; export TZ
