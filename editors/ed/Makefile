# $NetBSD: Makefile,v 1.24 2026/08/22 12:53:04 drixter Exp $

DISTNAME=		ed-1.22.6
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GNU:=ed/}
EXTRACT_SUFX=		.tar.lz

MAINTAINER=		drixter@e-utp.net
HOMEPAGE=		https://www.gnu.org/software/ed/ed.html
COMMENT=		GNU version of line-oriented text editor
LICENSE=		gnu-gpl-v3

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
USE_LANGUAGES=		c
USE_TOOLS+=		gmake

INFO_FILES=		yes

CONFIGURE_ARGS+=	--program-prefix=g

INSTALL_TARGET=		install install-man
TEST_TARGET=		check

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 gnu/bin gnu/${PKGMANDIR}/man1

post-install:
.for f in ed red
	${LN} -sf ${PREFIX}/bin/g${f} ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/${f}
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f}.1
.endfor

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
