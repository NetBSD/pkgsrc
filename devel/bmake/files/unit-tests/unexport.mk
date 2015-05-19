# $Id: unexport.mk,v 1.1.1.1 2015/05/19 21:36:45 joerg Exp $

# pick up a bunch of exported vars
.include "export.mk"

.unexport UT_ZOO UT_FOO

UT_TEST = unexport
