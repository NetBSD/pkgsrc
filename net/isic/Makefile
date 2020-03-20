# $NetBSD: Makefile,v 1.22 2020/03/20 11:58:07 nia Exp $
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

# XXX: this was originally added for NetBSD/alpha gcc-2.95.3, but then was
# XXX: made to apply to all NetBSD platforms without comment in -r1.18.  Check
# XXX: it is still required.
BUILDLINK_TRANSFORM.NetBSD+=	rm:-O[0-9]*

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/isic.README

.include "../../devel/libnet11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
