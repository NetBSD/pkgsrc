# $Id: unexport.mk,v 1.3 2020/05/24 11:09:44 nia Exp $

# pick up a bunch of exported vars
.include "export.mk"

.unexport UT_ZOO UT_FOO

UT_TEST = unexport
