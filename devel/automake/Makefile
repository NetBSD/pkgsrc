# $NetBSD: Makefile,v 1.18 2000/08/27 02:46:03 jlam Exp $
# FreeBSD Id: Makefile,v 1.5 1997/09/19 09:29:04 max Exp
#

DISTNAME=	automake-1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=automake/}

MAINTAINER=	fujimoto@oscar.elec.waseda.ac.jp
HOMEPAGE=	http://www.gnu.org/software/automake/automake.html

DEPENDS=	autoconf-2.13:../../devel/autoconf

USE_PERL5=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ENV=	PERL=${PERL5}
STRIPFLAG=	# none

INFO_FILES=	automake.info

.include "../../mk/bsd.pkg.mk"
