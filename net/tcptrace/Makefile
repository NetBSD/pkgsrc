# $NetBSD: Makefile,v 1.33 2011/12/07 15:18:51 joerg Exp $

DISTNAME=	tcptrace-6.6.7
CATEGORIES=	net
MASTER_SITES=	http://www.tcptrace.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcptrace.org/
COMMENT=	TCP dump file analysis tool

PKG_DESTDIR_SUPPORT=	user-destdir

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
