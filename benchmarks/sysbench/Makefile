# $NetBSD: Makefile,v 1.1.1.1 2007/03/05 15:55:25 rmind Exp $

DISTNAME=		sysbench-0.4.8
CATEGORIES=		benchmarks
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sysbench/}

MAINTAINER=		fuyuki@hadaly.org
HOMEPAGE=		http://sysbench.sourceforge.net/
COMMENT=		Modular, cross-platform and multi-threaded benchmark tool

BUILD_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

GNU_CONFIGURE=		yes
PTHREAD_AUTO_VARS=	yes
MAKE_FLAGS+=		bin_SCRIPTS= # don't install problematic scripts

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CFLAGS+=		-D_NETBSD_SOURCE # hack for ulong along with patch-aa
.endif

post-build:
	${PREFIX}/bin/xsltproc -o ${WRKSRC}/doc/manual.html \
		${PREFIX}/share/xsl/docbook/xhtml/docbook.xsl \
		${WRKSRC}/doc/manual.xml

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
