# $NetBSD: Makefile,v 1.18 2016/03/05 14:43:14 bsiegert Exp $

DISTNAME=		ed-1.13
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GNU:=ed/}
EXTRACT_SUFX=		.tar.lz

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnu.org/software/ed/ed.html
COMMENT=		GNU version of line-oriented text editor
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		YES

INFO_FILES=		yes

CONFIGURE_ARGS+=	--program-prefix=g

INSTALL_TARGET=		install install-man

AUTO_MKDIRS=		yes

.include "../../mk/bsd.prefs.mk"

post-install:
.for f in ed red
	${LN} -sf ${PREFIX}/bin/g${f} ${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/${f}
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}.1 ${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f}.1
.endfor

.include "../../mk/bsd.pkg.mk"
