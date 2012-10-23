# $NetBSD: Makefile,v 1.19 2012/10/23 17:18:30 asau Exp $
#

DISTNAME=	isic-0.07
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=isic/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://isic.sourceforge.net/
COMMENT=	Ip Stack Integrity Checker (IP, TCP, UDP, ICMP et. al.)
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	YES

INSTALLATION_DIRS+=	share/doc

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/isic.README

.include "../../devel/libnet11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# XXX On NetBSD, the egcs and gcc-2.95.3 for:
# XXX
# XXX     alpha
# XXX
# XXX has an optimization bug when compiling with -O2
#
.if ${OPSYS} == "NetBSD"
#.  if (${MACHINE_ARCH} == "alpha")
BUILDLINK_TRANSFORM+=	rm:-O[0-9]*
#.  endif
.endif
