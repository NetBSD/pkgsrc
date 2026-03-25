# $NetBSD: Makefile,v 1.67 2026/03/25 22:48:38 wiz Exp $

DISTNAME=	sed-4.9
PKGNAME=	g${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc editors
MASTER_SITES=	${MASTER_SITE_GNU:=sed/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/sed/sed.html
COMMENT=	GNU implementation of sed, the POSIX stream editor
LICENSE=	gnu-gpl-v3 AND gnu-fdl-v1.3

USE_GCC_RUNTIME=	yes
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
INFO_FILES=		YES
TEST_TARGET=		check

INSTALLATION_DIRS=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

# at least Solaris-2.9 has issues with grep/egrep
USE_TOOLS+=		grep makeinfo

CONFIGURE_ARGS+=	--program-prefix=g

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${OPSYS} == "QNX"
LIBS+=			-lgetopt
.endif

post-install:
.for g n in bin/gsed ${PKGGNUDIR}bin/sed ${PKGMANDIR}/man1/gsed.1 ${PKGGNUDIR}${PKGMANDIR}/man1/sed.1
	${LN} -sf ${PREFIX}/${g} ${DESTDIR}${PREFIX}/${n}
.endfor

.if ${OPSYS} == "QNX"
.include "../../devel/libgetopt/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
