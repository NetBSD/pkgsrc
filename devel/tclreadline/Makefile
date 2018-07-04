# $NetBSD: Makefile,v 1.8 2018/07/04 13:40:16 jperkin Exp $
#

DISTNAME=	tclreadline-2.1.0
PKGREVISION=	3
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tclreadline/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://tclreadline.sourceforge.net/
COMMENT=	GNU Readline library for interactive tcl shells
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${PREFIX}/lib

EGDIR=		${PREFIX}/share/examples/tclreadline

MESSAGE_SUBST+=		EGDIR=${EGDIR}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/pkgIndex.tcl.in
SUBST_FILES.paths+=	${WRKSRC}/tclreadlineInit.tcl.in
SUBST_FILES.paths+=	${WRKSRC}/tclreadlineSetup.tcl.in
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths=	-e 's,\/usr\/local,${PREFIX},'
SUBST_SED.paths+=	-e 's,\/usr\/locanl,${PREFIX},'

INSTALLATION_DIRS=	include ${PKGMANDIR}/mann lib \
			lib/tclreadline${PKGVERSION} ${EGDIR}

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/tclshrc ${DESTDIR}${EGDIR}/tclshrc

# Configure looks for termcap, but doesn't do anything with it
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
