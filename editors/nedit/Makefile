# $NetBSD: Makefile,v 1.5 1998/06/22 12:27:09 agc Exp $

DISTNAME=	nedit_source
PKGNAME=	nedit-5.0.2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.fnal.gov/pub/nedit/v5_0_2/

MAINTAINER=	tron@netbsd.org

USE_MOTIF=	yes

NO_WRKSUBDIR=	yes
NO_CONFIGURE=	yes
ALL_TARGET=	netbsd_nedit

post-extract:
.for DIR in source util
	@${LN} -s ${FILESDIR}/Makefile.${DIR} ${WRKSRC}/${DIR}/Makefile.netbsd
.endfor

do-install:
.for PROGRAM in nc nedit
	${INSTALL_PROGRAM} ${WRKSRC}/source/${PROGRAM} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PROGRAM}.man ${PREFIX}/man/man1/${PROGRAM}.1
.endfor
	${MKDIR} ${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nedit

.include "../../mk/bsd.pkg.mk"
