# $NetBSD: Makefile,v 1.5 2003/02/09 16:33:57 dmcmahill Exp $
#

DISTNAME=	isic-0.05
CATEGORIES=	net
MASTER_SITES=	http://expert.cc.purdue.edu/~frantzen/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://expert.cc.purdue.edu/~frantzen/
COMMENT=	Ip Stack Integrity Checker (IP, TCP, UDP, ICMP et. al.)

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/isic.README

.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# XXX On NetBSD, the egcs and gcc-2.95.3 for:
# XXX
# XXX     alpha
# XXX
# XXX has an optimization bug when compiling with -O2 
#
.if ${OPSYS} == "NetBSD"
.  if (${MACHINE_ARCH} == "alpha")
CPPFLAGS:=      ${CPPFLAGS:C/-O[0-9]*//g} 
CFLAGS:=        ${CFLAGS:C/-O[0-9]*//g}
CONFIGURE_ENV+= CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+= CFLAGS="${CFLAGS}"
.  endif
.endif
