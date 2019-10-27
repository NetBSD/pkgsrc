# $NetBSD: setuptools.py,v 1.7 2019/10/27 19:19:55 rillig Exp $

# This is a drop-in replacement for the setuptools Python module. Instead
# of actually searching for the dependencies, it extracts the dependency
# information and includes it in the generated pkgsrc package Makefile.


def url2pkg_print_depends(varname, depends):
    for dep in depends:
        print('%s\t%s%s' % (varname, dep.replace(' ', ''), '' if '>' in dep else '>=0'))


def url2pkg_print_var(varname, value):
    if value != '':
        print('var\t%s\t%s' % (varname, value))


def url2pkg_print_cmd(cmd, arg):
    print('\t'.join(('cmd', cmd, arg)))


def url2pkg_print_license(license_name):
    if license_name == '':
        return
    url2pkg_print_cmd('license', license_name)
    url2pkg_print_cmd(
        'license_default',
        '%s # TODO: from setup.py; needs to be adjusted' % license_name)


def setup(**kwargs):
    url2pkg_print_depends('DEPENDS', kwargs.get('requires', []))  # for distutils.core
    url2pkg_print_depends('DEPENDS', kwargs.get('install_requires', []))
    url2pkg_print_depends('TEST_DEPENDS', kwargs.get('tests_require', []))
    url2pkg_print_depends('BUILD_DEPENDS', kwargs.get('extras_require', {}).get('dev', []))
    url2pkg_print_depends('BUILD_DEPENDS', kwargs.get('setup_requires', []))
    url2pkg_print_var('COMMENT', kwargs.get('description', '').rstrip('.'))
    url2pkg_print_var('HOMEPAGE', kwargs.get('url', ''))
    url2pkg_print_license(kwargs.get('license', ''))

    # TODO: python_requires (see devel/py-futures)
    #       example: '>=2.6, <3, >=2.7, !=3.0.*, !=3.1.*, !=3.2.*, !=3.3.*')


def find_packages(where='.', exclude=(), include=('*',)):
    return []


# for distutils.core; see devel/py-pysha3-1.0.2 for an example
class Command:
    pass


# for distutils.extension; see devel/py-pysha3-1.0.2 for an example
class Extension:
    def __init__(self, *args, **kwargs):
        pass
