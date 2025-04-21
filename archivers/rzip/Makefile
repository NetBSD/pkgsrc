# $NetBSD: Makefile,v 1.15 2025/04/21 16:19:37 wiz Exp $

DISTNAME=	rzip-2.1
CATEGORIES=	archivers
MASTER_SITES=	https://rzip.samba.org/ftp/rzip/

MAINTAINER=	carton@Ivy.NET
HOMEPAGE=	https://rzip.samba.org/
COMMENT=	Create or extract .rz files, like gzip but smaller

GNU_CONFIGURE=		yes
INSTALL_MAKE_FLAGS+=	INSTALL_BIN=${DESTDIR}${PREFIX}/bin \
			INSTALL_MAN=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-install:
	${LN} -f ${DESTDIR}${PREFIX}/bin/rzip ${DESTDIR}${PREFIX}/bin/runzip
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/runzip.1
	${LN} -s rzip.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/runzip.1

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
