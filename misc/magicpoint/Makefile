# New ports collection makefile for:	magicpoint
# Version required:	1.04a
# Date created:		24 December 1997
# Whom:			itojun@itojun.org
#
# $NetBSD: Makefile,v 1.2 1999/06/15 04:33:11 itojun Exp $
# Based on FreeBSD Id: Makefile,v 1.8 1998/12/12 21:03:35 jseger Exp
#

DISTNAME=	magicpoint-1.04a
# question is for localized (i.e. Japanese) version
PKGNAME?=	magicpoint-1.04a
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.mew.org/pub/MagicPoint/

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.mew.org/mgp/

# plus sign is for localized (i.e. Japanese) version
DEPENDS+=	freetype-1.1:${.CURDIR}../../print/freetype

USE_IMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-vflib

post-configure:
	(cd ${WRKSRC}/contrib/xmindpath; ./configure --prefix=${PREFIX})

post-build:
	(cd ${WRKSRC}/contrib/xmindpath; make)

DOCS=	COPYRIGHT COPYRIGHT.jp README README.fonts README.fonts.jp \
	SYNTAX TODO.jp USAGE USAGE.jp
SAMPLES=	README README.jp ascii.mgp cloud.gif dad.eps dad.gif dns.mgp \
		default.mgp gradation.mgp mgp-old1.gif mgp-old2.gif \
		mgp-old3.gif mgp1.gif mgp2.gif mgp3.gif sample.mgp \
		tutorial.mgp v6.mgp v6header.eps v6header.gif
SAMPLES=	README README.jp cloud.gif dad.eps dad.gif default.mgp \
		dns-jp.mgp embed-jp.mgp embed.mgp gradation-jp.mgp \
		gradation.mgp mgp-old1.gif mgp-old2.gif mgp-old3.gif \
		mgp1.gif mgp2.gif mgp3.gif mgp3.xbm mgprc-sample \
		multilingual.mgp sample-jp.mgp sample.mgp sendmail6-jp.mgp \
		sendmail6.mgp tutorial-jp.mgp tutorial.mgp v6-jp.mgp \
		v6.mgp v6header.eps v6header.gif

# NOTE: there are some discussions/twists in gzip'ing xmindpath.1.
post-install:
	(cd ${WRKSRC}; make install.man)
	(cd ${WRKSRC}/contrib/xmindpath; make install)
#	${GZIP_CMD} ${PREFIX}/man/man1/xmindpath.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mgp
	for i in $(DOCS); do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/mgp; \
	done
	${MKDIR} ${PREFIX}/share/doc/mgp/sample
	for i in $(SAMPLES); do \
		${INSTALL_DATA} ${WRKSRC}/sample/$$i ${PREFIX}/share/doc/mgp/sample; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
