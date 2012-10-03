# $NetBSD: Makefile,v 1.15 2012/10/03 11:43:32 asau Exp $

DISTNAME=		ed-1.1
PKGREVISION=		2
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GNU:=ed/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnu.org/software/ed/ed.html
COMMENT=		GNU version of line-oriented text editor
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		YES

INFO_FILES=		yes

CONFIGURE_ARGS+=	--program-prefix=g

INSTALL_TARGET=		install install-man

AUTO_MKDIRS=		yes

post-install:
.for f in ed red
	${LN} -sf ${PREFIX}/bin/g${f} ${DESTDIR}${PREFIX}/gnu/bin/${f}
	${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}.1 ${DESTDIR}${PREFIX}/gnu/man/man1/${f}.1
.endfor

.include "../../mk/bsd.pkg.mk"
