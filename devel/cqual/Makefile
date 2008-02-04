# $NetBSD: Makefile,v 1.15 2008/02/04 20:10:35 tnn Exp $
#

DISTNAME=		cqual-0.991
PKGREVISION=		7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cqual/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.umd.edu/~jfoster/cqual/
COMMENT=		Tool for adding type qualifiers to C

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run bison m4

REPLACE_PERL+=		bin/*
INFO_FILES=		yes

INSTALLATION_DIRS=	share/doc/cqual share/examples/cqual

.include "options.mk"

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
