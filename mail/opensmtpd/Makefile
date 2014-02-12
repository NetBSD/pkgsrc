# $NetBSD: Makefile,v 1.2 2014/02/12 23:18:09 tron Exp $

VERSION=	5.3.3p1
DISTNAME=	opensmtpd-${VERSION}
PKGREVISION=	1
CATEGORIES=	mail net
MASTER_SITES=	http://www.opensmtpd.org/archives/

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://www.opensmtpd.org/
COMMENT=	The OpenSMTPD mail transfer agent, a replacement for sendmail
LICENSE=	isc AND modified-bsd AND 2-clause-bsd

CONFLICTS+=	courier-mta-[0-9]* fastforward>=0.51nb2 sendmail-[0-9]*
CONFLICTS+=	esmtp>=1.2 nullmailer-[0-9]* postfix-[0-9]*

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	automake aclocal autoheader autoconf

SMTPD_HOME=	${VARBASE}/chroot/smtpd
OWN_DIRS=	${SMTPD_HOME}

PKG_GROUPS=		_smtpd
PKG_USERS=		_smtpd:_smtpd
PKG_GECOS._smtpd=	OpenSMTPD pseudo-user
PKG_HOME._smtpd=	${SMTPD_HOME}

GNU_CONFIGURE=	yes

EXAMPLEDIR=	${PREFIX}/share/examples/opensmtpd
CONF_FILES=	${EXAMPLEDIR}/smtpd.conf ${PKG_SYSCONFDIR}/smtpd.conf

RCD_SCRIPTS=	opensmtpd

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/mailer.conf
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

SUBST_CLASSES+=			exampledir
SUBST_STAGE.exampledir=		pre-configure
SUBST_MESSAGE.exampledir=	Fixing exampledir path
SUBST_FILES.exampledir=		smtpd/Makefile.am
SUBST_SED.exampledir+=		-e 's,@EXAMPLE_DIR@,${EXAMPLEDIR},'

post-extract:
	cp ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf

pre-configure:
	set -e; cd ${WRKSRC} && ${SH} ./bootstrap

post-install:
	${INSTALL_DATA} ${WRKDIR}/mailer.conf \
		${DESTDIR}${EXAMPLEDIR}/mailer.conf

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
