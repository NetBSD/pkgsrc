# $NetBSD: Makefile,v 1.2 2002/12/06 15:29:20 cjep Exp $
# FreeBSD Id: Makefile,v 1.10 1999/01/27 07:41:16 fenner Exp $

DISTNAME=	grep-2.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=grep/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/grep/grep.html
COMMENT=	GNU grep

USE_BUILDLINK2=         YES
BUILD_USES_MSGFMT=	YES
TEXINFO_REQD=		4.0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=        --program-prefix=g

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
CONFIGURE_SCRIPT=	${SH} ./configure
.endif

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
