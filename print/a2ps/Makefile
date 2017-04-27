# $NetBSD: Makefile,v 1.82.2.1 2017/04/27 18:26:21 bsiegert Exp $

DISTNAME=		a2ps-4.14
PKGREVISION=		10
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=a2ps/}
MASTER_SITES+=		ftp://ftp.enst.fr/pub/unix/a2ps/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www-inf.enst.fr/~demaille/a2ps/
COMMENT=		Formats an ascii file for printing on a postscript printer

DEPENDS+=		psutils>=1.17:../../print/psutils

STRIP=			# empty

USE_LIBTOOL=		yes

.include "../../mk/bsd.prefs.mk"

CFLAGS.Darwin+=		-flat_namespace

USE_TOOLS+=		file:run gmake lex mktemp:run perl:run
CONFIGURE_ENV+=		file_prog=${FILE_CMD:Q}

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LPR=lpr
CONFIGURE_ARGS+=	--with-medium=${PAPERSIZE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	ac_cv_prog_EMACS=no

EGDIR=			${PREFIX}/share/examples/a2ps
CONF_FILES=		${EGDIR}/a2ps-site.cfg ${PKG_SYSCONFDIR}/a2ps-site.cfg
CONF_FILES+=		${EGDIR}/a2ps.cfg ${PKG_SYSCONFDIR}/a2ps.cfg
INFO_FILES=		yes

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
