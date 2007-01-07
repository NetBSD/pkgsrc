# $NetBSD: Makefile,v 1.25 2007/01/07 09:13:58 rillig Exp $

DISTNAME=	mailwrapper-19990412
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Wrapper to support arbitrary Mail Transport Agents

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

WRKSRC=			${WRKDIR}/mailwrapper
MANCOMPRESSED_IF_MANZ=	yes

EGDIR=			${PREFIX}/share/examples/mailwrapper

MAILWRAPPER_BACKUP_SFX=	.pkgsrc.mailwrapper
FILES_SUBST+=	MAILWRAPPER_BACKUP_SFX=${MAILWRAPPER_BACKUP_SFX:Q}

MAILWRAPPEES=	/usr/bin/mailq						\
		/usr/bin/newaliases	/usr/sbin/newaliases		\
		/usr/sbin/sendmail	/usr/lib/sendmail
FILES_SUBST+=	MAILWRAPPEES=${MAILWRAPPEES:Q}

INSTALLATION_DIRS=	${PKGMANDIR}/cat5 ${PKGMANDIR}/cat8 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin

do-configure:
	cd ${WRKSRC};							\
	for file in mailer.conf.5 mailwrapper.8 mailwrapper.c; do	\
		${MV} $$file $$file.save;				\
		${SED} -e "s|/etc/\(mailer.conf\)|${PKG_SYSCONFDIR}/\\1|g" \
			$$file.save > $$file;				\
	done

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/mailer.conf ${EGDIR}/mailer.conf.sendmail

.include "../../mk/bsd.pkg.mk"
