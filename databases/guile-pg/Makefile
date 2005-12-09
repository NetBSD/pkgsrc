# $NetBSD: Makefile,v 1.24 2005/12/09 16:01:10 gdt Exp $
#

DISTNAME=	guile-pg-0.29
CATEGORIES=	databases
MASTER_SITES=	http://www.glug.org/people/ttn/software/guile-pg/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.glug.org/people/ttn/software/guile-pg/
COMMENT=	PostgreSQL interface for Guile

USE_LIBTOOL=	YES
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

TEST_TARGET=	check

INFO_FILES=	guile-pg.info

# There are several versions of guile; the relevant ones for this
# module are 1.6.x, which is the current FSF version, and ttn-1.4,
# which is a forked version of 1.4 by Thien-Thi Nguyen, the maintainer
# of guile-pg.  fsf-1.4 is considered obsolete by nearly everyone.

# In 1.6 (but not fsf-1.4 or ttn-1.4), binary modules are deprecated.
# guile-pg uses binary modules, and places them and scheme code in
# $GUILE_LIBSITE, which is searched by ttn-1.4, but not by 1.6.  The
# simplest nonproblematic solution is to symlink the installed code to
# where 1.6 expects it.  We could patch guile-pg to install in 1.6's
# preferred location ${PREFIX}/share/guile/site, but there is a shared
# library which of course cannot go in share.

post-install:
	# guile should make this, but if not
	${INSTALL_DATA_DIR} ${PREFIX}/share/guile/site
	cd ${PREFIX}/share/guile/site && ${LN} -sf ../../../lib/guile/site/database .

PGSQL_VERSION_REQD=	74

.include "../../lang/guile/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
