# $NetBSD: Makefile,v 1.35 2013/02/06 19:31:02 jperkin Exp $

DISTNAME=	tcptrace-6.6.7
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.tcptrace.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcptrace.org/
COMMENT=	TCP dump file analysis tool

GNU_CONFIGURE=		yes

USE_TOOLS+=	bison flex

BUILD_TARGET=		tcptrace

DOCFILES=		COPYRIGHT FAQ README README.tput_graphs

LDFLAGS.SunOS+=		-lm

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/tcptrace

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tcptrace.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tcptrace.1
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/tcptrace
.endfor

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
