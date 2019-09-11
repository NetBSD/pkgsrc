# $NetBSD: setuptools.py,v 1.2 2019/09/11 05:25:55 rillig Exp $

def url2pkg_print_depends(keyword, depends):
    for dep in depends:
        print('%s\t%s%s' % (keyword, dep.replace(' ', ''), '' if '>' in dep else '>=0'))

def setup(**kwargs):
    if 'install_requires' in kwargs:
        url2pkg_print_depends('DEPENDS', kwargs['install_requires'])

    if 'tests_require' in kwargs:
        url2pkg_print_depends('TEST_DEPENDS', kwargs['tests_require'])

def find_packages(where='.', exclude=(), include=('*',)):
    return []
