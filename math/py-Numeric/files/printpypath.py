from distutils.sysconfig import get_python_inc
from distutils.sysconfig import get_python_lib

print "PYINC=" + get_python_inc(0, "")
print "PYSITELIB=" + get_python_lib(0, 0, "")
