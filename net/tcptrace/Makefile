# $NetBSD: Makefile,v 1.31 2007/01/07 09:14:07 rillig Exp $

DISTNAME=	tcptrace-6.6.7
CATEGORIES=	net
MASTER_SITES=	http://www.tcptrace.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcptrace.org/
COMMENT=	TCP dump file analysis tool

GNU_CONFIGURE=		yes

BUILD_TARGET=		tcptrace

DOCFILES=		COPYRIGHT FAQ README README.tput_graphs

LDFLAGS.SunOS+=		-lm

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tcptrace.man ${PREFIX}/${PKGMANDIR}/man1/tcptrace.1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcptrace
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/tcptrace
.endfor

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
