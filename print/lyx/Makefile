# $NetBSD: Makefile,v 1.53 2003/03/02 14:57:35 kei Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/14 16:46:50 andreas Exp
#

DISTNAME=		lyx-1.3.0
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.lyx.org/pub/lyx/stable/ \
			ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/ \
			ftp://ftp.sdsc.edu/pub/other/lyx/stable/

MAINTAINER=		martti@netbsd.org
HOMEPAGE=		http://www.lyx.org/
COMMENT=		Graphical frontend for LaTeX (nearly WYSIWYG)

DEPENDS=		ispell-base-[0-9]*:../../textproc/ispell-base
DEPENDS+=		teTeX2>=2.0.1:../teTeX2

USE_BUILDLINK2=		YES
USE_PERL5=		YES
USE_GMAKE=		YES
USE_X11=		YES
USE_CXX=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+= 	--with-extra-prefix=${BUILDLINK_PREFIX.xforms} \
			--with-pspell-lib=${BUILDLINK_PREFIX.aspell}/lib \
			--with-pspell-include=${BUILDLINK_PREFIX.aspell}/include/pspell \
			--with-pspell
CXXFLAGS+=		-Wno-non-template-friend -ftemplate-depth-30

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "sparc64"
DBG=	-O -ffixed-g4	#Hack for embedany memory model compatibility
.else
DBG=	-O
.endif

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

# IPv6 support
.if defined(LYX_USE_QT) && !empty(LYX_USE_QT:M[Yy][Ee][Ss])
.include "../../x11/qt3-tools/buildlink2.mk"
CONFIGURE_ARGS+= 	--with-extra-prefix=${BUILDLINK_PREFIX.qt3-libs} \
			--with-qt-dir=${QTDIR} \
			--with-qt-includes=${BUILDLINK_PREFIX.qt3-libs}/qt3/include \
			--with-qt-libraries=${BUILDLINK_PREFIX.qt3-libs}/qt3/lib \
			--with-frontend=qt
.else
.include "../../x11/xforms/buildlink2.mk"
CONFIGURE_ARGS+= 	--with-extra-prefix=${BUILDLINK_PREFIX.xforms} \
			--with-frontend=xforms
.endif

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../lang/gcc/buildlink2.mk"
.include "../../textproc/aiksaurus/buildlink2.mk"
.include "../../textproc/aspell/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
