#!/bin/sh
#
# $NetBSD: checkusers.sh,v 1.1.1.1 2001/08/13 09:10:10 zuntum Exp $

QMAILDIR=@QMAILDIR@
USER_CMD=@USER_CMD@
GROUP_CMD=@GROUP_CMD@

create_group()
{
	GROUP=$1
	
	${GROUP_CMD} info -e ${GROUP}
	if [ $? -eq 0 ]; then
		echo "Group '${GROUP}' already exists... proceeding."
	else
		echo -n "Creating '${GROUP}' group... "
		${GROUP_CMD} add ${GROUP}
		echo "done."
	fi

	return
}

create_user()
{
	USER=$1
	GROUP=$2

	if [ "$USER" = alias ];  then
		HOME="$QMAILDIR/alias"
	else
		HOME="$QMAILDIR"
	fi

	${USER_CMD} info -e ${USER}
	if [ $? -eq 0 ]; then
		echo "User '${USER}' already exists... proceeding."
	else
		echo -n "Creating '${USER}' user... "
		${USER_CMD} add -g ${GROUP} -s /sbin/nologin -d ${HOME} ${USER}
		echo "done."
	fi

	return
}

create_group qmail
create_group nofiles

create_user alias nofiles
create_user qmaill nofiles
create_user qmaild nofiles
create_user qmailp nofiles
create_user qmailq qmail
create_user qmailr qmail
create_user qmails qmail
