# $NetBSD: Makefile,v 1.6 2011/08/07 16:11:16 cheusov Exp $

DISTNAME=	mcast-tools-20061214
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcast-tools/}

MAINTAINER=	is@NetBSD.org
COMMENT=	IPv6 multicast routing daemons and tools

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

CONFLICTS=	pim6sd-[0-9]* pim6dd-[0-9]*

GNU_CONFIGURE=	yes

USE_TOOLS+=	yacc lex

INSTALLATION_DIRS= share/examples/mcast-tools

post-install:
	${INSTALL_DATA} ${WRKSRC}/pim6sd/pim6sd.conf.sample ${DESTDIR}${PREFIX}/share/examples/mcast-tools
	${INSTALL_DATA} ${FILESDIR}/pim6dd.conf.sample ${DESTDIR}${PREFIX}/share/examples/mcast-tools
	${INSTALL_DATA} ${WRKSRC}/mfc/mfc.conf.sample ${DESTDIR}${PREFIX}/share/examples/mcast-tools

.include "../../mk/bsd.pkg.mk"
