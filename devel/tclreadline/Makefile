# $NetBSD: Makefile,v 1.11 2020/03/20 11:57:33 nia Exp $
#

DISTNAME=	tclreadline-2.1.0
PKGREVISION=	4
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tclreadline/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://tclreadline.sourceforge.net/
COMMENT=	GNU Readline library for interactive tcl shells
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-tcl=${PREFIX}/lib

# Need real readline; otherwise rl_extend_line_buffer is undefined
READLINE_DEFAULT=	readline

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
