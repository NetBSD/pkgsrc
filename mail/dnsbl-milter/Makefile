# $NetBSD: Makefile,v 1.1 2014/05/13 15:31:40 sborrill Exp $
#

VERSION=	6.40
PKGNAME=	dnsbl-milter-${VERSION}
DISTNAME=	dnsbl-${VERSION}
CATEGORIES=	mail
MASTER_SITES=	http://www.five-ten-sg.com/dnsbl/packages/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.five-ten-sg.com/dnsbl/
COMMENT=	DNSBL Sendmail milter
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
PKG_SYSCONFSUBDIR?=	dnsbl-milter
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/${PKG_SYSCONFSUBDIR}

USE_LANGUAGES=	c c++

RCD_SCRIPTS=		dnsbl-milter

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	src/dnsbl.cpp
SUBST_FILES.conf+=	src/tokenizer.cpp
SUBST_FILES.conf+=	src/context.cpp
SUBST_SED.conf+=	-e "s|@CONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.conf=	Fixing paths for configuration

EGDIR=		share/examples/dnsbl-milter

CONFS=		dnsbl.conf hosts-ignore.conf tld.conf html-tags.conf
.for f in ${CONFS}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

INSTALLATION_DIRS=	${EGDIR} ${PKGMANDIR}/man1 ${PKGMANDIR}/man5
INSTALL_DIRS=	src man

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} ${CONFS} ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
