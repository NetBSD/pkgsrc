# $NetBSD: Makefile,v 1.23 2013/04/01 15:26:26 dholland Exp $
#

DISTNAME=		cqual-0.991
PKGREVISION=		10
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cqual/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.cs.umd.edu/~jfoster/cqual/
COMMENT=		Tool for adding type qualifiers to C

MAKE_JOBS_SAFE=		no
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl:run bison m4

REPLACE_PERL+=		bin/*
INFO_FILES=		yes

BUILDLINK_TRANSFORM=	rm:-Werror
INSTALLATION_DIRS=	share/doc/cqual share/examples/cqual

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && ${OS_VERSION} == "5.8"
pre-build:
	${ECHO} "/* empty dummy header */" > ${BUILDLINK_DIR:Q}/include/stdint.h
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC:Q}/doc/user-guide.pdf ${DESTDIR}${PREFIX}/share/doc/cqual/
	${INSTALL_DATA} ${WRKSRC:Q}/examples/* ${DESTDIR}${PREFIX}/share/examples/cqual/

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
