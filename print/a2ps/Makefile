# $NetBSD: Makefile,v 1.51.2.1 2005/06/09 20:05:49 snj Exp $

DISTNAME=		a2ps-4.13b
PKGNAME=		a2ps-4.13.0.2
PKGREVISION=		7
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=a2ps/} \
			ftp://ftp.enst.fr/pub/unix/a2ps/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www-inf.enst.fr/~demaille/a2ps/
COMMENT=		Formats an ascii file for printing on a postscript printer

DEPENDS+=		papersize>=1.0.2:../../print/papersize
DEPENDS+=		psutils>=1.17:../../print/psutils

.include "../../mk/bsd.prefs.mk"

.if empty(OPSYS:M*BSD)
DEPENDS+=		mktemp>=1.5:../../sysutils/mktemp
.endif

WRKSRC=			${WRKDIR}/a2ps-4.13
STRIP=			# empty

USE_BUILDLINK3=		yes
USE_PERL5=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		LPR=lpr
CONFIGURE_ARGS+=	--with-medium="${PAPERSIZE}"
CONFIGURE_ARGS+=	--sysconfdir="${PKG_SYSCONFDIR}"

EGDIR=			${PREFIX}/share/examples/a2ps
CONF_FILES=		${EGDIR}/a2ps-site.cfg ${PKG_SYSCONFDIR}/a2ps-site.cfg
CONF_FILES+=		${EGDIR}/a2ps.cfg ${PKG_SYSCONFDIR}/a2ps.cfg

INFO_FILES=		a2ps.info ogonkify.info regex.info

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
