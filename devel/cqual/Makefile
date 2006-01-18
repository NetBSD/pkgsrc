# $NetBSD: Makefile,v 1.6 2006/01/18 23:24:12 rillig Exp $
#

DISTNAME=		cqual-0.991
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cqual/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://cqual.sourceforge.net/
COMMENT=		Tool for adding type qualifiers to C

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run

REPLACE_PERL+=		bin/*

INSTALLATION_DIRS=	share/doc/cqual share/examples/cqual

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && ${OS_VERSION} == "5.8"
pre-build:
	${ECHO} "/* empty dummy header */" > ${BUILDLINK_DIR:Q}/include/stdint.h
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC:Q}/doc/user-guide.pdf ${PREFIX:Q}/share/doc/cqual/
	${INSTALL_DATA} ${WRKSRC:Q}/examples/* ${PREFIX:Q}/share/examples/cqual/

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
