# $NetBSD: Makefile,v 1.1.1.1 2005/10/07 22:59:48 wulf Exp $

DISTNAME=	gnuradio-core-2.5
COMMENT=        Runtime system and DSP blocks for GNU Radio

PYTHON_PATCH_SCRIPTS+=		src/lib/filter/generate_all.py
PYTHON_PATCH_SCRIPTS+=		src/lib/general/generate_all.py
PYTHON_PATCH_SCRIPTS+=		src/lib/swig/gen-swig-bug-fix

.include "../../meta-pkgs/gnuradio/Makefile.common"

.include "../../devel/swig13/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
