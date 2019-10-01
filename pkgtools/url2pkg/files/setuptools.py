# $NetBSD: setuptools.py,v 1.3 2019/10/01 19:41:23 rillig Exp $

# This is a drop-in replacement for the setuptools Python module. Instead
# of actually searching for the dependencies, it extracts the dependency
# information and includes it in the generated pkgsrc package Makefile.

url2pkg_license_mapping = {
    'Apache 2': 'apache-2.0',
    'Apache 2.0': 'apache-2.0',
    'Apache Software License': '', # too unspecific; needs a version number
    'BSD': '', # too unspecific
    'GNU Lesser General Public License (LGPL), Version 3': 'gnu-lgpl-v3',
    'LGPL': 'gnu-lgpl-v2',
    'MIT': 'mit',
    'MIT License': 'mit',
    'PSF': 'python-software-foundation',
    'PSF license': 'python-software-foundation',
    'Python Software Foundation License': 'python-software-foundation',
    'ZPL 2.1': 'zpl-2.1',
}

def url2pkg_print_depends(keyword, depends):
    for dep in depends:
        print('%s\t%s%s' % (keyword, dep.replace(' ', ''), '' if '>' in dep else '>=0'))

def url2pkg_print_var(varname, value):
    if value != '':
        print('var\t%s\t%s' % (varname, value))

def url2pkg_print_license(license):
    if license == '':
        return
    pkgsrc_license = url2pkg_license_mapping.get(license, '')
    if pkgsrc_license == '':
        url2pkg_print_var('#LICENSE', '%s # TODO: from setup.py; needs to be adjusted' % license)
    else:
        url2pkg_print_var('LICENSE', pkgsrc_license)

def setup(**kwargs):
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
