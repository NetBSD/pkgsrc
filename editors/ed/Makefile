# $NetBSD: Makefile,v 1.21 2022/01/21 02:27:04 wen Exp $

DISTNAME=		ed-1.17
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GNU:=ed/}
EXTRACT_SUFX=		.tar.lz

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		https://www.gnu.org/software/ed/ed.html
COMMENT=		GNU version of line-oriented text editor
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
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

.include "../../mk/bsd.pkg.mk"
