# $NetBSD: Makefile,v 1.11 2002/12/07 02:38:59 schmonz Exp $

DISTNAME=	mailwrapper-19990412
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
COMMENT=	NetBSD 1.4's wrapper to support arbitrary Mail Transport Agents

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

NO_CONFIGURE=		yes
MANCOMPRESSED_IF_MANZ=	yes

.if exists(/usr/sbin/mailwrapper)
PKG_SKIP_REASON= "${PKGNAME} is part of your ${OPSYS} distribution"
.endif

WRKSRC=		${WRKDIR}/mailwrapper

MAILER_CONF=	/etc/mailer.conf
LIBEXECDIR=	/usr/libexec/sendmail
SENDMAIL=	/usr/sbin/sendmail

post-install:
	${INSTALL_DATA} ${WRKSRC}/mailer.conf ${PREFIX}/etc/mailer.conf.default
	${TEST} -e ${MAILER_CONF} || \
	${LN} -s ${PREFIX}/etc/mailer.conf.default /etc/mailer.conf
	${INSTALL_DATA_DIR} ${LIBEXECDIR}
	${MV} -i ${SENDMAIL} ${LIBEXECDIR} </dev/null 2>/dev/null || ${TRUE}
	${LN} -fs ${PREFIX}/sbin/mailwrapper /usr/bin/mailq
	${LN} -fs ${PREFIX}/sbin/mailwrapper /usr/bin/newaliases
	${LN} -fs ${PREFIX}/sbin/mailwrapper ${SENDMAIL}

.include "../../mk/bsd.pkg.mk"
