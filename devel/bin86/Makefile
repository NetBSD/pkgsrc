# $NetBSD: Makefile,v 1.4 2012/10/31 11:16:40 asau Exp $

DISTNAME=		bin86-0.16.17
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://homepage.ntlworld.com/robert.debath/dev86/ \
			http://www.debath.co.uk/dev86/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.debath.co.uk/
COMMENT=		Simple assembler and linker for x86 machine code

CONFLICTS=		bcc-[0-9]*
CONFLICTS+=		dev86-[0-9]*

USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${GMAKE} PREFIX=${PREFIX:Q}

do-install:
	cd ${WRKSRC} && ${GMAKE} PREFIX=${DESTDIR}${PREFIX} PKGMANDIR=${PKGMANDIR} install

.include "../../mk/bsd.pkg.mk"
