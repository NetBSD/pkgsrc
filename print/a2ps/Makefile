# $NetBSD: Makefile,v 1.38 2002/11/28 10:25:32 tron Exp $

DISTNAME=		a2ps-4.13b
PKGNAME=		a2ps-4.13.0.2
PKGREVISION=		2
WRKSRC=			${WRKDIR}/a2ps-4.13
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=a2ps/} \
			ftp://ftp.enst.fr/pub/unix/a2ps/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www-inf.enst.fr/~demaille/a2ps/
COMMENT=		Formats an ascii file for printing on a postscript printer

DEPENDS+=		papersize>=1.0.2:../../print/papersize
DEPENDS+=		psutils>=1.17:../../print/psutils

STRIP=			# empty
USE_PERL5=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/auxdir/ltconfig

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LPR=lpr
CONFIGURE_ARGS+=	--with-medium="${PAPERSIZE}"
CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"
AUTOMAKE_OVERRIDE=	NO

EGDIR=			${PREFIX}/share/examples/a2ps
CONF_FILES=		${EGDIR}/a2ps-site.cfg ${PKG_SYSCONFDIR}/a2ps-site.cfg
CONF_FILES+=		${EGDIR}/a2ps.cfg ${PKG_SYSCONFDIR}/a2ps.cfg

INFO_FILES=		a2ps.info ogonkify.info regex.info

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
