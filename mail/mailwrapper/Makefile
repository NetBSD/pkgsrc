# $NetBSD: Makefile,v 1.13 2003/05/01 12:10:11 jmmv Exp $

DISTNAME=	mailwrapper-19990412
PKGREVISION=	1
WRKSRC=		${WRKDIR}/mailwrapper
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
COMMENT=	NetBSD 1.4's wrapper to support arbitrary Mail Transport Agents

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

USE_PKGINSTALL=		yes
NO_CONFIGURE=		yes
MANCOMPRESSED_IF_MANZ=	yes

.if exists(/usr/sbin/mailwrapper)
PKG_SKIP_REASON= "${PKGNAME} is part of your ${OPSYS} distribution"
.endif

EGDIR=		${PREFIX}/share/examples/mailwrapper
CONF_FILES=	${EGDIR}/mailer.conf ${PKG_SYSCONFDIR}/mailer.conf

LIBEXECDIR=	/usr/libexec/sendmail
SENDMAIL=	/usr/sbin/sendmail

post-patch:
.for f in mailer.conf.5 mailwrapper.8 mailwrapper.c
	${SED} -e 's|/etc/mailer.conf|${PKG_SYSCONFDIR}/mailer.conf|g' \
		< ${WRKSRC}/$f > ${WRKSRC}/$f.new
	${MV} ${WRKSRC}/$f.new ${WRKSRC}/$f
.endfor
.undef f

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/mailer.conf ${EGDIR}/mailer.conf
	${INSTALL_DATA_DIR} ${LIBEXECDIR}
	${MV} -i ${SENDMAIL} ${LIBEXECDIR} </dev/null 2>/dev/null || ${TRUE}
	${LN} -fs ${PREFIX}/sbin/mailwrapper /usr/bin/mailq
	${LN} -fs ${PREFIX}/sbin/mailwrapper /usr/bin/newaliases
	${LN} -fs ${PREFIX}/sbin/mailwrapper ${SENDMAIL}

.include "../../mk/bsd.pkg.mk"
