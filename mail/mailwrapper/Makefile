# $NetBSD: Makefile,v 1.28 2012/10/08 12:19:16 asau Exp $

DISTNAME=	mailwrapper-19990412
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Wrapper to support arbitrary Mail Transport Agents

USE_FEATURES+=		cdefs
USE_BSD_MAKEFILE=	yes

WRKSRC=			${WRKDIR}/mailwrapper

EGDIR=			${PREFIX}/share/examples/mailwrapper

MAILWRAPPER_BACKUP_SFX=	.pkgsrc.mailwrapper
FILES_SUBST+=	MAILWRAPPER_BACKUP_SFX=${MAILWRAPPER_BACKUP_SFX:Q}

MAILWRAPPEES=	/usr/bin/mailq						\
		/usr/bin/newaliases	/usr/sbin/newaliases		\
		/usr/sbin/sendmail	/usr/lib/sendmail
FILES_SUBST+=	MAILWRAPPEES=${MAILWRAPPEES:Q}

INSTALLATION_DIRS=	${PKGMANDIR}/cat5 ${PKGMANDIR}/cat8 \
			${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin \
			share/examples/mailwrapper

do-configure:
	cd ${WRKSRC};							\
	for file in mailer.conf.5 mailwrapper.8 mailwrapper.c; do	\
		${MV} $$file $$file.save;				\
		${SED} -e "s|/etc/\(mailer.conf\)|${PKG_SYSCONFDIR}/\\1|g" \
			$$file.save > $$file;				\
	done

post-install:
	${INSTALL_DATA} ${WRKSRC}/mailer.conf ${DESTDIR}${EGDIR}/mailer.conf.sendmail

.include "../../mk/bsd.pkg.mk"
