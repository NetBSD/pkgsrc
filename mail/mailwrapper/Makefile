# $NetBSD: Makefile,v 1.19 2004/08/10 21:46:34 jlam Exp $

DISTNAME=	mailwrapper-19990412
PKGREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	wrapper to support arbitrary Mail Transport Agents

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

WRKSRC=			${WRKDIR}/mailwrapper
MANCOMPRESSED_IF_MANZ=	yes

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
EGDIR=			${PREFIX}/share/examples/mailwrapper

MAILWRAPPER_BACKUP_SFX=	.pkgsrc.mailwrapper
FILES_SUBST+=	MAILWRAPPER_BACKUP_SFX=${MAILWRAPPER_BACKUP_SFX}

MAILWRAPPEES=	/usr/bin/mailq						\
		/usr/bin/newaliases	/usr/sbin/newaliases		\
		/usr/sbin/sendmail	/usr/lib/sendmail
FILES_SUBST+=	MAILWRAPPEES=${MAILWRAPPEES:Q}

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
