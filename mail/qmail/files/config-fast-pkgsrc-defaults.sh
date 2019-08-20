# $NetBSD: config-fast-pkgsrc-defaults.sh,v 1.1 2019/08/20 02:38:04 schmonz Exp $

SORT=@SORT@
MV=@MV@
CP=@CP@

PKG_SYSCONFDIR=@PKG_SYSCONFDIR@
QMAIL_QUEUE_EXTRA=@QMAIL_QUEUE_EXTRA@

cd ${PKG_SYSCONFDIR}/.pkgsrc-defaults-do-not-edit
for i in locals rcpthosts; do
	${SORT} -u ${i} > ${i}.tmp && ${MV} ${i}.tmp ${i}
done

cd ${PKG_SYSCONFDIR}
for i in defaultdomain locals me plusdomain rcpthosts; do
	[ -f control/${i} ] \
		|| ${CP} .pkgsrc-defaults-do-not-edit/${i} control
done

cd ${PKG_SYSCONFDIR}/alias
for i in mailer-daemon postmaster root ${QMAIL_QUEUE_EXTRA}; do
	[ -s .qmail-${i} ] \
		|| echo '# pkgsrc says: replace this comment with your config' \
		> .qmail-${i}
	chmod 644 .qmail-${i}
done
