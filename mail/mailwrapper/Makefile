# $NetBSD: Makefile,v 1.27 2012/03/02 16:30:32 hans Exp $

DISTNAME=	mailwrapper-19990412
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Wrapper to support arbitrary Mail Transport Agents

PKG_DESTDIR_SUPPORT=	user-destdir

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
