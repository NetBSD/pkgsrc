# $NetBSD: Makefile,v 1.9 2001/02/17 18:24:52 wiz Exp $

DISTNAME=	mailwrapper-19990412
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
COMMENT=	NetBSD 1.4's wrapper to support arbitrary Mail Transport Agents

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

NO_CONFIGURE=		yes
MANCOMPRESSED_IF_MANZ=	yes

.if exists(/usr/sbin/mailwrapper)
IGNORE=         "${PKGNAME} is part of your NetBSD distribution"
.endif

WRKSRC=		${WRKDIR}/mailwrapper

MAILER_CONF=	/etc/mailer.conf
LIBEXECDIR=	/usr/libexec/sendmail
SENDMAIL=	/usr/sbin/sendmail

post-install:
	${INSTALL_DATA} ${WRKSRC}/mailer.conf ${PREFIX}/etc/mailer.conf.default
	${TEST} -e ${MAILER_CONF} || \
	${LN} -s ${PREFIX}/etc/mailer.conf.default /etc/mailer.conf
	${MKDIR} ${LIBEXECDIR}
	${MV} -i ${SENDMAIL} ${LIBEXECDIR} </dev/null 2>/dev/null || ${TRUE}
	${LN} -fs ${PREFIX}/sbin/mailwrapper /usr/bin/mailq
	${LN} -fs ${PREFIX}/sbin/mailwrapper /usr/bin/newaliases
	${LN} -fs ${PREFIX}/sbin/mailwrapper ${SENDMAIL}

.include "../../mk/bsd.pkg.mk"
