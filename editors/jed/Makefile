# $NetBSD: Makefile,v 1.21 2003/04/05 20:29:41 wiz Exp $
#

DISTNAME=		jed-0.99-16
PKGNAME=		jed-0.99.16
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.jedsoft.org/pub/davis/jed/v0.99/ \
			ftp://ftp.fu-berlin.de/pub/unix/editors/jed/v0.99/ \
			ftp://ftp.ntua.gr/pub/lang/slang/jed/v0.99/ \
			ftp://ftp.bay.net.au/pub/jed/v0.99/ \
			ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/jed/v0.99/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@gmx.net
HOMEPAGE=		http://www.jedsoft.org/jed/
COMMENT=		Extensible folding editor with Emacs/WordStar/EDT emulations

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-X

EGDIR=			${PREFIX}/share/examples/jed
CONF_FILES=		${EGDIR}/jed.conf ${PREFIX}/etc/jed.conf

post-install:
	${RMDIR} ${PREFIX}/share/jed/bin
	${RMDIR} ${PREFIX}/share/jed/lib/tm
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/jed.conf ${EGDIR}

.include "../../mk/bsd.pkg.install.mk"
.include "../../devel/libslang/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
