# $NetBSD: Makefile,v 1.13 2003/12/03 17:08:24 recht Exp $
#

DISTNAME=	mono-0.29
CATEGORIES=	lang
MASTER_SITES=	http://www.go-mono.org/archive/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.go-mono.org/
COMMENT=	Open source implementation of the .NET Development Framework

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison

# XXX please test
NOT_FOR_PLATFORM=	NetBSD-1.[0-5]*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6-* NetBSD-1.6.*-*
NOT_FOR_PLATFORM+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[AB]-*

USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-gc=included
CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libgc/libtool

PKGCONFIG_OVERRIDE=	mono.pc.in
PKG_SYSCONFSUBDIR=	mono

USE_PERL5=	build
REPLACE_PERL=	mono/cil/make-opcodes-def.pl
REPLACE_PERL+=	mono/metadata/make-bundle.pl

EGDIR=		${PREFIX}/share/examples/mono
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=	${EGDIR}/machine.config ${PKG_SYSCONFDIR}/machine.config
CONF_FILES+=	${EGDIR}/DefaultWsdlHelpGenerator.aspx ${PKG_SYSCONFDIR}/DefaultWsdlHelpGenerator.aspx

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/icu/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
