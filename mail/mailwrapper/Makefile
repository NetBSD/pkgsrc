# $NetBSD: Makefile,v 1.1.1.1 1999/04/12 21:19:32 tron Exp $

DISTNAME=	mailwrapper-19990412
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tron@netbsd.org

MIRROR_DISTFILE=	no
NO_CONFIGURE=		yes
NO_PATCH=		yes

.if exists(/usr/sbin/mailwrapper)
IGNORE=         "is part of your NetBSD distribution"
.endif

MANCOMPRESSED=	1
WRKSRC=		${WRKDIR}/mailwrapper

MAILER_CONF=	/etc/mailer.conf
LIBEXECDIR=	/usr/libexec/sendmail
SENDMAIL=	/usr/sbin/sendmail

post-install:
	${INSTALL_DATA} ${WRKSRC}/mailer.conf ${PREFIX}/etc/mailer.conf.default
	${TEST} -e ${MAILER_CONF} || \
	${LN} -s ${PREFIX}/etc/mailer.conf.default /etc/mailer.conf
	${MKDIR} ${LIBEXECDIR}
	${MV} ${SENDMAIL} ${LIBEXECDIR}
	${LN} -fs ${PREFIX}/sbin/mailwrapper /usr/bin/mailq
	${LN} -fs ${PREFIX}/sbin/mailwrapper /usr/bin/newaliases
	${LN} -fs ${PREFIX}/sbin/mailwrapper ${SENDMAIL}

.include "../../mk/bsd.pkg.mk"
