# $NetBSD: Makefile,v 1.18 2001/12/17 22:29:04 mjl Exp $

DISTNAME=		gnucash-1.6.5
CATEGORIES=		finance
MASTER_SITES=		http://www.linas.org/pub/gnucash/gnucash/sources/stable/ \
			ftp://ftp.gnucash.org/pub/gnucash/sources/stable/ \
			${MASTER_SITE_SOURCEFORGE:=gnucash/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnucash.org/
COMMENT=		Personal double-entry accounting program

DEPENDS+=		eperl-2.2.14:../../textproc/eperl
DEPENDS+=		g-wrap>=1.1.10:../../devel/g-wrap
DEPENDS+=		guppi>=0.35.5nb1:../../math/guppi
DEPENDS+=		libperl>=${LIBPERL5_REQD}:../../lang/libperl
DEPENDS+=		popt>=1.5:../../devel/popt
DEPENDS+=		swig-1.1p5:../../devel/swig

LIBPERL5_REQD=		${PERL5_REQD}

USE_GMAKE=		YES
USE_PERL5=		YES
USE_X11BASE=		YES
USE_LIBINTL=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-guile-config=${LOCALBASE}/bin/guile-config
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--with-perl-includes=${PERL5_ARCHLIB}
CONFIGURE_ARGS+=	--with-perl=${PERL5}

CONFIGURE_ENV+=		LOCALBASE="${LOCALBASE}"
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD)
CPPFLAGS+=		-I${WRKSRC}/include

post-extract:
	${MKDIR} ${WRKSRC}/include
	${LN} -s /usr/include/db.h ${WRKSRC}/include/db_185.h
.if !exists(/usr/include/wctype.h)
	${TOUCH} ${WRKSRC}/include/wctype.h
.endif
.endif

.include "../../mk/bsd.pkg.mk"
